#!/bin/bash

echo "Please input commit info in AngularJS form (<type>(topic): details):"
read -p "Enter the type of commit:" type
read -p "Enter the topic of commit:" topic
read -p "Enter the details of commit:" details
read -p "Enter the branch of commit:" branch

./Link_Gen.sh
git checkout -b $branch
git add .
git commit -m "$type($topic): $details"
git push git@github.com:KKtheGhost/Kivinsae-LeetCode-C.git main