#ok lets begin

class Mutableclass():
    
    def __init__(self,sting):
        self.characters=list(sting)
    
    def __str__(self):
        return "".join(self.characters)
    
    def __repr__(self):
        return(str(self)) 
    
    def __contains__(self,word):
        return  word in self.characters
    
    def __getitem__(self,index):
        return    self.characters[index]
    
    def __len__(self):
        return len(self.characters)
    
    def __add__(self,word):
        self.characters=list(str(self)+str(word))

    def __setitem__(self,index,letter):
        self.characters[index]=letter

    def __getattribute__(self, name):              #thsi i belive is the most important function
        return getattr(str(self),name)