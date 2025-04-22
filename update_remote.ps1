$timestamp = Get-Date -Format "yyyy-MM-dd HH:mm:ss"
Write-Output "Updating submodules..."

# Use 'cmd' to evaluate inner script for each submodule
git submodule foreach --recursive {
	$submoduleName = $args[0]
		$commitMsg = "Auto-commit: update in submodule $submoduleName on $timestamp"
		Write-Output "[$submoduleName] Committing with message: $commitMsg"

		git add .
		git commit -m "$commitMsg" 2>$null
		if ($LASTEXITCODE -ne 0) {
			Write-Output "[$submoduleName] Nothing to commit"
		} else {
			git push || Write-Output "[$submoduleName] Push failed"
		}
} $name

# Commit changes in main repo
$mainMsg = "Auto-commit: updated submodule references on $timestamp"
Write-Output "Main repo commit: $mainMsg"
git add .
git commit -m "$mainMsg" 2>$null
if ($LASTEXITCODE -ne 0) {
	Write-Output "Nothing to commit in main repo"
} else {
	git push
}
