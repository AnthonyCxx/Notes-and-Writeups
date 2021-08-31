# Event-driven Programming (Signals and Slots)
GUIs are fundamentally built on a paradigm of programming called [event-driven programming](https://en.wikipedia.org/wiki/Event-driven_programming), which make GUIs interactive. Event-driven programming is composed of _events_ and _event handlers_ such that whenever the user performs specific actions (like clicking a button), it triggers a [callback function](https://en.wikipedia.org/wiki/Callback_(computer_programming)) that performs some sort of action (like submitting an answer). 

In Qt, [Widgets](https://www.pythonguis.com/tutorials/pyqt-basic-widgets/) like send out _signals_ when an event related to them occurs (like the text of a textbox updating);
these signals are recieved by _slots_, which are functions that can be bound to a widget. Any function can be a slot, but they must be able to receive the data the signal sends.

Here's a good article on signals and slots: PythonGUIs: [Signals, Slots & Events](https://www.pythonguis.com/tutorials/pyqt-signals-slots-events/).

## Creating a Functioning Button

```Python
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton

class MainWindow(QMainWindow):
    def __init__(self):
        # Call the constructor of 'QMainWindow'
        super().__init__()

        # Create a button and link it to the method 'on_click'
        button = QPushButton("Press the button.")    # Create a button labled 'Press the button.'
        button.clicked.connect(self.on_click)        # Set the action to take when pressed

        # Set the button as the central widget of the window
        self.setCentralWidget(button)

    def on_click(self):
        print("Pressed the button!")        

def main():
    # Create QApplication
    app = QApplication([])
    
    # Create a main window and then show it
    window = MainWindow()
    window.show()

    # Start the event loop
    app.exec_()

if __name__ == '__main__':
    main()
```
