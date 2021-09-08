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
_.setText()_ changes the text displayed by a QLabel.

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
        
        # 
        self.widgets.setLayout(self.layout)
        self.setCentralWidget(self.widgets)

        # init
        self.show()

    def on_click(self):
        self.label.setText("You pressed the button!")
```
