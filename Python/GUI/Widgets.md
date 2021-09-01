# Widgets in PyQt5
"Widgets are basic building blocks of an application. PyQt5 has a wide range of various widgets, including buttons, check boxes, sliders, or list boxes." ([Zetcode](https://zetcode.com/gui/pyqt5/widgets/)). There are _many_ widgets in Qt (a full list can be found [here](https://doc.qt.io/qt-5/qtwidgets-module.html#details)), only the most
essential of which I'll be covering here.

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
