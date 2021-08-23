# Analyzing a Linux System
This is going to be centered around Ubuntu, but the concepts are generally applicable.

## Get OS Info
[How to Check OS Version in Linux via the Commandline](https://www.cyberciti.biz/faq/how-to-check-os-version-in-linux-command-line/)

```bash
cat /etc/os-release
```

## Finding Installed Packages

### Installed Packages
[How to List Installed Packages on Ubuntu](https://linuxize.com/post/how-to-list-installed-packages-on-ubuntu/)
```bash
apt list --installed
```

### Uninstalled Packages
[Get the list of packages that got removed from Ubuntu/Debian](https://rebugged.com/get-the-list-of-packages-removed-from-ubuntu-debian/)

```bash
cat /var/log/apt/history.log
```
