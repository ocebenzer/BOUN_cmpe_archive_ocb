class scalar():
    name = ""
    type = "scalar"
    value = None

    def __init__(self, name):
        self.name = name


class vector():
    name = ""
    type = "vector"
    size = None
    value = []

    def __init__(self, name, size):
        self.name = name
        self.size = size


class matrix():
    name = ""
    type = "matrix"
    size = None
    value = []

    def __init__(self, name, row, column):
        self.name = name
        self.size = [row, column]
