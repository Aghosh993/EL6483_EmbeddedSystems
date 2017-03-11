#!/bin/bash
if [ $# -eq 0 ]
	then
		echo "Usage: ./rename_project.sh NEW_PROJECT_NAME OLD_PROJECT_NAME"
		echo "Example: ./rename_project.sh bar foo --> Rename a project currently named \"foo\" to \"bar\"."
		exit 0
fi

OLD_PROJ_NAME=$2
NEW_PROJ_NAME=$1

if [ -d $OLD_PROJ_NAME ]; then
	echo "Renaming project..."
else
	echo "ERROR: Project not found!!"
	exit 0
fi


mv $OLD_PROJ_NAME $NEW_PROJ_NAME
if [ -f $NEW_PROJ_NAME/$OLD_PROJ_NAME.c ]; then
	mv $NEW_PROJ_NAME/$OLD_PROJ_NAME.c $NEW_PROJ_NAME/$NEW_PROJ_NAME.c
else
	if [ -f $NEW_PROJ_NAME/$OLD_PROJ_NAME.s ]; then
		mv $NEW_PROJ_NAME/$OLD_PROJ_NAME.s $NEW_PROJ_NAME/$NEW_PROJ_NAME.s
	else
		echo "WARNING: No valid source file found for user app!!"
	fi
fi
echo $NEW_PROJ_NAME > $NEW_PROJ_NAME/proj_name
sed -i "s/$OLD_PROJ_NAME/$NEW_PROJ_NAME/g" $NEW_PROJ_NAME/runme.gdb
sed -i "s/$OLD_PROJ_NAME/$NEW_PROJ_NAME/g" $NEW_PROJ_NAME/Makefile
