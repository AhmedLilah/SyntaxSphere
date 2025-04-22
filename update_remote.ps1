# update_remote.ps1

$timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
Write-Host "Updating submodules..."

# Get all submodule paths from .gitmodules
$submodules = git config --file .gitmodules --get-regexp path | ForEach-Object {
	($_ -split " ")[1]
}

foreach ($submodule in $submodules) {
	if (Test-Path $submodule) {
		Push-Location $submodule

			$currentBranch = git rev-parse --abbrev-ref HEAD
			if ($currentBranch -eq "HEAD") {
				Write-Host "[$submodule] Skipped: Detached HEAD"
					Pop-Location
					continue
			}

		$commitMsg = "Auto-commit: update in submodule $submodule on $timestamp"
			Write-Host "[$submodule] Committing with message: $commitMsg"

			git add .
			git commit -m "$commitMsg" 2>$null
			if ($LASTEXITCODE -ne 0) {
				Write-Host "[$submodule] Nothing to commit"
			} else {
				git push || Write-Host "[$submodule] Push failed"
			}

		Pop-Location
	} else {
		Write-Host "[$submodule] Skipped: path '$submodule' does not exist."
	}
}

# Commit submodule reference updates in main repo
$mainMsg = "Auto-commit: updated submodule references on $timestamp"
Write-Host "Main repo commit: $mainMsg"
git add .
git commit -m "$mainMsg" 2>$null
if ($LASTEXITCODE -ne 0) {
	Write-Host "Nothing to commit in main repo"
} else {
	git push
}
