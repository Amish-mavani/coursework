Steps Installation and configuration:

sudo apt-get install snort*

sudo nano /etc/snort/snort.conf

sudo snort -i wl01 -c /etc/snort/snort.conf  -T

sudo nano /etc/snort/rules/local.rules

Run:

sudo snort -i wl01 -c /etc/snort/snort.conf  -A console
