list=$(ls -la /sys/block/sd* | awk '{print $9}')

for t in ${list[@]}; do
	output=$(udevadm info -a -p ${t}| grep serial | cut -d \" -f2)
	c=0
    for i in ${output[@]}; do
        
        if [[ $c -eq 0 ]]
        then
            echo ATTRS{serial}=='"'$i'"',ENV{UDISKS_IGNORE}='"0"' >> 99-usb.rules;
        fi
        let "c += 1"
    done
done

