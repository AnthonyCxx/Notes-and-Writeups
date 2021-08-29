# Introduction to GUI Programming with Python and PyQt5

A simple, blank window.
```Python
import PyQt5.QtWidgets

class MainWindow(PyQt5.QtWidgets.QWidget):
    # Constructor
    def __init__(self):
        super().__init__()

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
