ldapsearch -x 'uid=z*' | grep 'cn:' | cut -c5- | sort -r
