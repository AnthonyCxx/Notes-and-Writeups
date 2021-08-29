# Introduction to GUI Programming with Python and PyQt5

## A Simple Window

```Python
import PyQt5.QtWidgets

class MainWindow(PyQt5.QtWidgets.QWidget):
    # Constructor
    def __init__(self):
        super().__init__()

        # Add a title to the window
        self.setWindowTitle("Hello, world!")

        # Display the window
        self.show()


# // DRIVER CODE // #
def main():
    app = PyQt5.QtWidgets.QApplication([])
    window = MainWindow()

    app.exec_()

if __name__ == '__main__':
    main()
```
> I suggest you abbreviate things like _PyQt5.QtWidgets_ as _qtw_ for sake of brevity. I didn't for clarity's sake.

## Adding Layouts
The _self.setLayout()_ method defines the type of window that is displayed. <br />
Just a few of the layouts are _QVBoxLayout()_, _QHBoxLayout()_, and _QGridLayout()_. Click [here](https://coderslegacy.com/python/pyqt-layout-management/) for examples of the three.

```Python
import PyQt5.QtWidgets

class MainWindow(PyQt5.QtWidgets.QWidget):
    # Constructor
    def __init__(self):
        super().__init__()

        # Add a title to the window
        self.setWindowTitle("Hello, world!")

        # Set layout
        self.setLayout(PyQt5.QtWidgets.QHBoxLayout())

        # Display the window
        self.show()


# // DRIVER CODE // #
def main():
    app = PyQt5.QtWidgets.QApplication([])
    window = MainWindow()

    app.exec_()

if __name__ == '__main__':
    main()
```

## Customizing Layouts with Widgets
You can add items to the window by adding widgets to the _self.layout()_ function.
Widgets are the basic building blocks of GUIs, as they are the "components of the UI that the user can interact with" ([source](https://www.pythonguis.com/tutorials/pyqt-basic-widgets/)). You may know widgets as things like buttons, check boxes, or progress bars.

```Python
import PyQt5.QtWidgets

class MainWindow(PyQt5.QtWidgets.QWidget):
    # Constructor
    def __init__(self):
        super().__init__()

        # Add a title to the window
        self.setWindowTitle("Hello, world!")

        # Set layout
        self.setLayout(PyQt5.QtWidgets.QHBoxLayout())

        # Add some text to the layout
        text = PyQt5.QtWidgets.QLabel("Hello, world!")
        self.layout().addWidget(text)

        # Display the window
        self.show()


# // DRIVER CODE // #
def main():
    app = PyQt5.QtWidgets.QApplication([])
    window = MainWindow()

    app.exec_()

if __name__ == '__main__':
    main()
```
