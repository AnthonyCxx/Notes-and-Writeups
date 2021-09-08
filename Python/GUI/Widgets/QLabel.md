# QLabel
"QLabel is used for displaying text or an image. No user interaction functionality is provided. The visual appearance of the label can be configured in various ways, 
and it can be used for specifying a focus mnemonic key for another widget." -[Qt Documentation](https://doc.qt.io/qt-5/qlabel.html#details)

## Displaying Text
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

## Displaying Images


```Python

```

## A Full Example
If you don't get the joke, [read this](https://medium.com/@philosotramp/diogenes-versus-plato-fa8a68e8be2f).

As for the image I used, you can find it [here](https://www.google.com/url?sa=i&url=https%3A%2F%2Fbmcgenomics.biomedcentral.com%2Farticles%2F10.1186%2F1471-2164-13-257&psig=AOvVaw2gqFn-Fe7I8bLqGneoBWa2&ust=1631222509322000&source=images&cd=vfe&ved=0CAsQjRxqFwoTCLj22cOn8PICFQAAAAAdAAAAABAD)
```Python
class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # Window title
        self.setWindowTitle("Diogenes, the Sarcastic")

        # Text at the top of the screen
        self.label = QLabel("Behold, a man!") 
        font = QFont('Garamond', 30)
        font.setBold(True)
        self.label.setFont(font)
        self.label.setAlignment(Qt.AlignHCenter | Qt.AlignTop)

        # Central image
        self.image = QLabel()
        self.image.setPixmap(QPixmap(r"C:\Users\ethan\Downloads\FeatherlessChicken.jpg"))

        # Create the containers
        self.widgets = QWidget()
        self.layout = QVBoxLayout()
        
        # Add the widgets to the layout
        self.layout.addWidget(self.label)
        self.layout.addWidget(self.image)
    
        # Layout
        self.widgets.setLayout(self.layout)
        self.setCentralWidget(self.widgets)

        # init
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

### _.setAlignment()_
[.setAlignment()](https://www.geeksforgeeks.org/qt-alignment-in-pyqt5/) can set the alignment of a _QLabel_ to one of a set of defaults:
Qt.AlignLeft, Qt.AlignRight, Qt.AlignBottom, Qt.AlignTop, Qt.AlignCenter, Qt.AlignHCenter, or Qt.AlignVCenter. To use multiple alignments, join them with a vertical
line like `.setAlignment(Qt.AlignHCenter | Qt.AlignTop)`.

This program infintely cycles through all the alignment options to give you a visual representation of how they work.
```Python
from PyQt5.QtCore import Qt
from itertools import cycle

class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # List of possible alignments + an iterator/generator
        self.alignments = ['Qt.AlignLeft', 'Qt.AlignRight', 'Qt.AlignBottom', 'Qt.AlignTop', \
                           'Qt.AlignCenter ', 'Qt.AlignHCenter ', 'Qt.AlignVCenter', 'Qt.AlignJustify']
        self.alignment_iter = self.alignment_generator()

        # Widgets
        self.label = QLabel("Press the button to change the alignment of the text!") 
        self.button = QPushButton("Press the button.")    # Create a button labled 'Press the button.'
        self.button.clicked.connect(self.on_click)        # Set the action to take when pressed

        # Create the containers
        self.widgets = QWidget()
        self.layout = QVBoxLayout()
        
        # Add the widgets to the layout
        self.layout.addWidget(self.label)
        self.layout.addWidget(self.button)
        
        # Layout
        self.widgets.setLayout(self.layout)
        self.setCentralWidget(self.widgets)

        # init
        self.show()

    def on_click(self):
        alignment = next(self.alignment_iter)
        self.label.setText(alignment)
        self.label.setAlignment(eval(alignment))  # Evaluates the string as if it were hard-coded

    def alignment_generator(self):
        for alignment in cycle(self.alignments):
            yield alignment
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
        self.label.setFont(QFont('Garamond', 30, italic=True))  # Font, size, italics

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
