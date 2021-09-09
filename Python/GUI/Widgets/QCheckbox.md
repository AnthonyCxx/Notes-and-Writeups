# QCheckbox in PyQt5
"A QCheckBox is an option button that can be switched on (checked) or off (unchecked). Checkboxes are typically used to represent features in an application that
can be enabled or disabled without affecting others. Different types of behavior can be implemented. For example, a QButtonGroup can be used to group check buttons logically, 
allowing exclusive checkboxes. However, QButtonGroup does not provide any visual representation." - [Qt Documentation](https://doc.qt.io/qt-5/qcheckbox.html)

## Basic Usage
from PyQt5.QtWidgets import QApplication, QHBoxLayout, QMainWindow, QCheckBox, QWidget
from PyQt5.QtCore import Qt

```Python
class MainWindow(QMainWindow):
    def __init__(self):
        super().__init__()

        # Checkbox
        self.box = QCheckBox("\'check\' me out")
        self.box.toggled.connect(self.on_check)

        # Containers 
        self.widgets = QWidget()
        self.layout = QHBoxLayout()

        # Add widgets to layout
        self.layout.addWidget(self.box, alignment=Qt.AlignCenter)

        # Set window format
        self.widgets.setLayout(self.layout)
        self.setCentralWidget(self.widgets)

        # init
        self.show()

    # Event: when the user checks the checkbox
    def on_check(self, is_checked):
        if is_checked:
            print("Checked!")
        else:
            print("Not checked!")
```

# Methods

## 

##

##
