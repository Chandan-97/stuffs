from asyncore import write
class LCD:
    def __init__(self, str):
        self.val_arr = list(str)
        self.val_arr = self.val_arr[1]
        for i in range(len(self.val_arr)):
            try:
                if(self.val_arr[i] == '\n'):
                    self.val_arr.remove('\n')
                else:
                    pass
            except Exception as e:
                pass
            
        LCD.LCD_VAL = []
        LCD.row3 = [' _ ', "   ", " _ ", " _ ", "   ", " _ ", " _ ", " _ ", " _ ", " _ "]
        LCD.row2 = ['| |', "  |", " _|", " _|", "|_|", "|_ ", "|_ ", "  |", "|_|", "|_|"]
        LCD.row1 = ['|_|', "  |", "|_ ", " _|", "  |", " _|", "|_|", "  |", "|_|", " _|"]
        LCD.row0 = ['   ', "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   "]
    
    def doit(self):
        
        print_3 = ""
        try:
            self.val_arr.remove('\n')
        except Exception as e:
            pass
         
        for val_val in self.val_arr:
            try:
                print_3 += LCD.row3[int(val_val)]
            except Exception as e:
                pass
#         print(print_3)
        
        print_2 = ""
        for val_val in self.val_arr:
            try:
                print_2 += LCD.row2[int(val_val)]
            except Exception as e:
                pass
#         print(print_2)
        
        print_1 = ""
        for val_val in self.val_arr:
            try:
                print_1 += LCD.row1[int(val_val)]
            except Exception as e:
                pass
#         print(print_1)
        
        print_0 = ""
        for val_val in self.val_arr:
            try:
                print_0 += LCD.row0[int(val_val)]
            except Exception as e:
                pass
        print(print_0)
        
        return [print_3, print_2, print_1, print_0]
            

try:
    write_file = open("output.out", "w")
    with open("input.in", "r") as file:
        for line in enumerate(file):
            str_val = line
            current = LCD(str_val)
            ans = current.doit()
            for row in ans:
                print(row)
                write_file.write(row)
                write_file.write("\n")
    write_file.close()
except Exception as e:
    print(e)
    
