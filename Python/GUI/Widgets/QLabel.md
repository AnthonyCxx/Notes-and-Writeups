# QLabel
"QLabel is used for displaying text or an image. No user interaction functionality is provided. The visual appearance of the label can be configured in various ways, 
and it can be used for specifying a focus mnemonic key for another widget." -[Qt Documentation](https://doc.qt.io/qt-5/qlabel.html#details)

```Python
class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        self.label = QLabel("This is some text")
        self.initWindow()

    def initWindow(self):
        self.setCentralWidget(self.label)
        self.show()
```

# Methods

## _.setText()_

```Python

```
