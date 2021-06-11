# Notes for Ubuntu Server 21.04 on the Raspberry Pi

## Setting Up Wi-Fi

### Step 1: Edit the Netplan
1. Edit the network configuration file _50-cloud-init.yaml_ (Path: _/etc/netplan/50-cloud-init.yaml_)
> Make sure you use sudo. Do `sudo vim /etc/netplan/50-cloud-init.yaml`.

2. Your file should look like this: 
```yaml
# This file is generated from information provided by the datasource. Changes
# to it will not persist across and instance reboot. To disable cloud-init's
# network configuration capabilities, write a file
# /etc/cloud/cloud.cfg.d/99-disable-network-config.cfg with the following:
# network: {config: disabled}
network:
    ethernets:
        eth0:
            dhcp4: true
            optional: true
        version: 2
        wifis:
            wlan0:
                optional: true
                access-points:
                    "WiFi SSID (name) goes here":
                        password: "WiFi password goes here"
                dhcp4: true
```
> YAML files are _heavily_ indent-based. Each indent here must be 4 spaces, not a tab. <br />
> This the the proper setup most of the time, but sometimes it's not. Click [_here_](https://huobur.medium.com/how-to-setup-wifi-on-raspberry-pi-4-with-ubuntu-20-04-lts-64-bit-arm-server-ceb02303e49b) if it's not working for you.

### Step 2: Debug the Netplan
The command `sudo netplan --debug generate` will make sure that your indentation is correct.

### Step 3: Apply the Netplan
Apply the configured netplan with `sudo netplan apply`.

### Step 4: Reboot the System
Reboot: `sudo reboot`.
