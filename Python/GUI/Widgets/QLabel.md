## QLabel
_QLabel_ can display text or images.

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
