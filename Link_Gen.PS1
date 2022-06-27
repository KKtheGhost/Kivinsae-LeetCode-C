Remove-Item Difficulty/Easy/*
Remove-Item Difficulty/Medium/*
Remove-Item Difficulty/Hard/*

foreach ($file in Get-ChildItem .\All\ | Select -exp Name) {
    $lastLine = Get-Content .\All\$file -Tail 1
    $Difficulty = $lastLine.split(' ')[2]
    if ($Difficulty -match "EASY") {
        cmd /c mklink /H .\Difficulty\Easy\$file .\All\$file
    }
    elseif ($Difficulty -match "MEDIUM") {
        cmd /c mklink /H .\Difficulty\Medium\$file .\All\$file
    }
    else {
        cmd /c mklink /H .\Difficulty\Hard\$file .\All\$file
    }
}

echo "Soft link regenerate finished."