#!/bin/bash
# backup_folder.sh

SOURCE=~/backup
DEST=~/backup_$(date +%Y%m%d).tar.gz

# Check if source exists
if [ -d "$SOURCE" ]; then
    tar -czf "$DEST" -C "$SOURCE" .
    echo "Backup successful: $DEST"
else
    echo "Source folder does not exist: $SOURCE"
fi

