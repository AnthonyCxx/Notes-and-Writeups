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
_.setText()_ changes the text displayed by a QLabel. This class has a button that changes the text to "You pressed the button!" when pressed.

```Python
class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # Widgets
        self.label = QLabel("...") 
        self.button = QPushButton("Press the button.")    # Create a button labled 'Press the button.'
        self.button.clicked.connect(self.on_click)        # Set the action to take when pressed

        # Create the containers
        self.widgets = QWidget()
        self.layout = QVBoxLayout()
        
        # Add the widgets to the layout
        self.layout.addWidget(self.label)
        self.layout.addWidget(self.button)
        
        # Set window format
        self.widgets.setLayout(self.layout)
        self.setCentralWidget(self.widgets)

        # Display window
        self.show()

    def on_click(self):
        self.label.setText("You pressed the button!")
```


## _.setFont()_
The _.setFont()_ method changes the font of the text; it takes a [_QFont_](https://doc.qt.io/qt-5/qfont.html) object with the specified font as a string and other optional 
modifiers such as italics. All the available fonts are determined by the [QFontDatabase](https://doc.qt.io/qt-5/qfontdatabase.html) class.

```Python
from PyQt5.QtGui import QFont

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # Widgets
        self.label = QLabel("Hey, this isn't Comic Sans!") 

        # Widget settings
        self.label.setFont(QFont('Garamond', 30))  # Font, size

        # Create the containers
        self.widgets = QWidget()
        self.layout = QVBoxLayout()
        
        # Add the widgets to the layout
        self.layout.addWidget(self.label)
        
        # Set window format
        self.widgets.setLayout(self.layout)
        self.setCentralWidget(self.widgets)

        # Display window
        self.show()
```
