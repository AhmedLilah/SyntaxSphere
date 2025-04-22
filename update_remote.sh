#!/bin/bash

timestamp=$(date +"%Y-%m-%d %H:%M:%S")

echo "Updating submodules..."

git submodule foreach '
submodule_name=$name
commit_msg="Auto-commit: update in submodule $submodule_name on '"$timestamp"'"
echo "[$submodule_name] Committing with message: $commit_msg"
git add .
git commit -m "$commit_msg" || echo "[$submodule_name] Nothing to commit"
git push || echo "[$submodule_name] Push failed"
'

# Now commit the updated submodule refs in the parent repo
main_msg="Auto-commit: updated submodule references on $timestamp"
echo "Committing in main repo: $main_msg"
git add .
git commit -m "$main_msg" || echo "Nothing to commit in main repo"
git push
