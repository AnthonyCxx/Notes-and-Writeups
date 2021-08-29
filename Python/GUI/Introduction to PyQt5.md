# Introduction to GUI Programming with Python and PyQt5
PyQt5 has three major modules: [_QtWidgets_](https://docs.huihoo.com/pyqt/PyQt5/QtWidgets.html), [_QtGui_](https://docs.huihoo.com/pyqt/PyQt5/QtGui.html) and [_QtCore_](https://docs.huihoo.com/pyqt/PyQt5/QtCore.html), each of which contains a set of tools necessary for creating a user interface (UI). <br />
Qt uses an [event-driven system](https://www.technologyuk.net/computing/software-development/software-design/event-driven-programming.shtml) which responds to user input
by spawning an event, which then results in action.

## Creating and Empty Window
```Python
from PyQt5.QtWidgets import QApplication, QWidget

# Create QApplication
app = QApplication([])  # QApplication is given no arguments (typically a list of strings)

# Create a widget (which we're using as a blank window) and then show it
window = QWidget()
window.show()        # <-- Show the window. Windows without a parent are hidden by default.

# Start the event loop (show the window)
app.exec_()
```
> [QApplication](https://doc.qt.io/qtforpython-5/PySide2/QtWidgets/QApplication.html#detailed-description) is a [singleton](https://en.wikipedia.org/wiki/Singleton_pattern) that contains the [event loop](https://en.wikipedia.org/wiki/Event_loop#:~:text=In%20computer%20science%2C%20the%20event,or%20messages%20in%20a%20program.&text=When%20the%20event%20loop%20forms,loop%20or%20main%20event%20loop.) necessary for the user to interact with the window.

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
