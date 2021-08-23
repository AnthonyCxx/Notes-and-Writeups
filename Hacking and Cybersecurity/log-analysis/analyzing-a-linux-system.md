# Analyzing a Linux System
This is going to be centered around Ubuntu.

## Finding Installed Packages

### Installed Packages

```bash
apt list --installed | grep
```

### Uninstalled Packages
[Get the list of packages that got removed from Ubuntu/Debian](https://rebugged.com/get-the-list-of-packages-removed-from-ubuntu-debian/)

```bash
cat /var/log/apt/history.log | grep
```
