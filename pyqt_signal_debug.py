from PyQt5.QtCore import *

Slot = pyqtSlot
Signal = pyqtSignal


def setup_signal_debug(obj):
    def debug_slot(obj_name, name, *args):
        print('{}: {}({})'.format(obj_name, name, ', '.join(map(repr, args))))

    for attr_name in dir(obj):
        attr = getattr(obj, attr_name)
        if isinstance(attr, pyqtBoundSignal):
            slot_args = attr.signal.split('(')[1][:-1]

            if slot_args:
                slot_args = slot_args.split(',')
            else:
                slot_args = ()

            slot = Slot(*slot_args, name=attr_name)(partial(debug_slot, obj.objectName(), attr_name))
            attr.connect(slot)
