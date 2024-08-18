foldername=$@
foldername=$(echo $foldername | sed "s/ /-/" )

if [ $# -gt 0 ]; then
    mkdir $foldername
    cp -r .template/* $foldername
else 
    # echo error 
    echo "DUUUUDE, that folder already existsssss"
fi