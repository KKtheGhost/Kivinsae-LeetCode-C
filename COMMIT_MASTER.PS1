echo "Please input commit info in AngularJS form (<type>(topic): details):"
$type= Read-Host -Prompt "Enter the type of commit"
$topic= Read-Host -Prompt "Enter the topic of commit"
$details= Read-Host -Prompt "Enter the details of commit"
$branch= Read-Host -Prompt "Enter wished branch to push"

./Link_Gen.PS1
git checkout -b $branch
git add .
git commit -m "$type($topic): $details"
git push git@github.com:KKtheGhost/Kivinsae-LeetCode-C.git $branch