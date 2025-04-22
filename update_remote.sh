#!/bin/bash

timestamp=$(date +"%Y-%m-%d %H:%M:%S")
echo "Updating submodules..."

# Get list of all submodule paths
mapfile -t submodules < <(git config --file .gitmodules --get-regexp path | awk '{print $2}')

for submodule in "${submodules[@]}"; do
	if [[ -d "$submodule" ]]; then
		pushd "$submodule" > /dev/null

		current_branch=$(git rev-parse --abbrev-ref HEAD)
		if [[ "$current_branch" == "HEAD" ]]; then
			echo "[$submodule] Skipped: Detached HEAD"
			popd > /dev/null
			continue
		fi

		commit_msg="Auto-commit: update in submodule $submodule on $timestamp"
		echo "[$submodule] Committing with message: $commit_msg"

		git add .
		if git commit -m "$commit_msg" > /dev/null 2>&1; then
			if ! git push; then
				echo "[$submodule] Push failed"
			fi
		else
			echo "[$submodule] Nothing to commit"
		fi

		popd > /dev/null
	else
		echo "[$submodule] Skipped: path '$submodule' does not exist."
	fi
done

# Commit submodule reference updates in main repo
main_msg="Auto-commit: updated submodule references on $timestamp"
echo "Main repo commit: $main_msg"

git add .
if git commit -m "$main_msg" > /dev/null 2>&1; then
	git push
else
	echo "Nothing to commit in main repo"
fi
