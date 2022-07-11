Write-Output "Please input the LeetCode language you want to switch:"
$lclang= Read-Host -Prompt "Enter the Programming language name:"

Copy-Item .\.vscode\lc_settings_${lclang}.json -Destination "$HOME\AppData\Roaming\Code\User\settings.json" -Recurse -force