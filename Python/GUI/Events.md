# Event-driven Programming (Signals and Slots)
GUIs are fundamentally built on a paradigm of programming called [event-driven programming](https://en.wikipedia.org/wiki/Event-driven_programming), which make GUIs interactive. Event-driven programming is composed of _events_ and _event handlers_ such that whenever the user performs specific actions (like clicking a button), it triggers a [callback function](https://en.wikipedia.org/wiki/Callback_(computer_programming)) that performs some sort of action (like submitting an answer). 

In Qt, [Widgets](https://www.pythonguis.com/tutorials/pyqt-basic-widgets/) like send out _signals_ when an event related to them occurs (like the text of a textbox updating);
these signals are recieved by _slots_, which are functions that can be bound to a widget. Any function can be a slot, but they must be able to receive the data the signal sends.

Here's a good article on signals and slots: PythonGUIs: [Signals, Slots & Events](https://www.pythonguis.com/tutorials/pyqt-signals-slots-events/).

## Creating an Iteractive Button
Creating a simple, iteractive button is really as easy as binding a function to the button using the _QPushButton.clicked.connect()_ method.

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

## Receiving Data from a Singal
When the button is clicked, it sends a signal containing data about the button's state. So, binding a function to _button_ that takes a parameter will call that function
when the button is pushed. When evaluating whether the button is toggled or not, make sure you have _QPushButton.setCheckable()_ to _True_, otherwise the button will always
return _False_. Buttons can be pressed and togged in the same click, since the methods are not mutually exclusive. In that case, both the _on\_click()_ and _on\_toggle()_ method will be called.

If you want to access the state of the button without pushing it, you have to save the state in a data member of the class such as '_self.is_on_'.
```Python
from PyQt5.QtWidgets import QApplication, QMainWindow, QPushButton

class MainWindow(QMainWindow):
    def __init__(self):
        # Call the constructor of 'QMainWindow'
        super().__init__()

        # Create a button and link it to the method 'on_click'
        button = QPushButton("Press the button.")    # Create a button labled 'Press the button.'
        button.setCheckable(True)                    # Set button to register being toggled
        button.clicked.connect(self.on_toggle)       # Set the action to take when toggled

        # Set the button as the central widget of the window
        self.setCentralWidget(button) 

    def on_toggle(self, state):
        print(f"Button is now {'on' if state else 'off'}")

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
