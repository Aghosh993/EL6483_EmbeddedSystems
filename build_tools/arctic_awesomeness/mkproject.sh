#!/bin/bash
if [ $# -eq 0 ]
	then
		echo "Usage: ./mkproject.sh PROJECT_NAME [F3/F4]"
		echo "Example: ./mkproject.sh foo F3 --> Make an F3 Discovery project named foo."
		exit 0
fi

PROJ_NAME=$1
PROJ_PLATFORM=$2

if [ "$2" = "F3" ] || [ "$2" = "f3" ]; then
	echo "Creating F3 Discovery project..."
else
	if [ "$2" = "F4" ] || [ "$2" = "f4" ]; then
		echo "Creating F4 Discovery project..."
	else
		echo "ERROR! Invalid platform!!"
		exit 0
	fi
fi

cp -r f3_basic_app/ $PROJ_NAME
mv $PROJ_NAME/f3_basic_app.c $PROJ_NAME/$PROJ_NAME.c
echo $PROJ_NAME > $PROJ_NAME/proj_name
sed -i "s/f3_basic_app/$PROJ_NAME/g" $PROJ_NAME/runme.gdb
