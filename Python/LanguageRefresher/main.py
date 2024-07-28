# chain of responsability design pattern

class BaseValidator():
    def __init__(self, next): 
        self.next = next
    def validate(self, string):
        if self.next != None:
            return self.next.validate(string)
        return True

class lengthValidator(BaseValidator):
    def validate(self, string):
        if len(string) >= 20:
            if self.next != None:
                return self.next.validate(string)
            return True
        return False

class SpecialCharacterValidator(BaseValidator):
    def validate(self, string):
        if string.find("@") != -1:
            if self.next != None:
                return self.next.validate(string)
            return True
        return False

class gmailValidator(BaseValidator):
    def validate(self, string):
        if string.find("gmail") != -1:
            if self.next != None:
                return self.next.validate(string)
            return True
        return False

scv = SpecialCharacterValidator(None)
gv = gmailValidator(scv)
lv = lengthValidator(gv)
v = BaseValidator(lv)

strs = ["ahmedsabry2325667@gmail.com", "Hellow, World!", "ahmedsabry2325667@outlook.com", "fklasdjfljadklsfjklsdjfklsdjflkjsaklfjklsdjfkl;jads"]

for strr in strs:
    print(v.validate(strr))
