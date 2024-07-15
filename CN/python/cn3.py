import PyPDF2
import random
start = 0
end = 0
pdfFileObj = open('Lorem_ipsum.pdf', 'rb')
pdfReader = PyPDF2.PdfReader(pdfFileObj)
pageObj=pdfReader.pages[0]
file_pdf=pageObj.extract_text()
ascii_string=""

for char in file_pdf:
    ascii_string+=str(ord(char))

with open('Char_frame.txt', 'w') as f:
     c=0
     while end<len(file_pdf):
         power=random.randint(5,10)
         end += 2**power
         f.write(str(2**power)+" "+file_pdf[start:end])
         f.write("\n\n\n")   
         start = end 
         c += 1
     pdfFileObj.close()

class Frame:
     data=''
     size = 0
     def __init__(self,data,n):
          self.size=n
          count=0
          framecontainer ='01111110'
          self.data += framecontainer
          
          for i in data:
             if i == '':
                  continue
             count+=1
          
          if count<n: 
             self.data += data
             self.data +='1'
             diff = n-count
             while diff-1 != 0:
                 self.data += '0'
                 diff -= 1
          else:
             self.data+=data
         
          self.data += framecontainer
     
def bitStuffing(sig):
     onecounter = 0
     index = 0
     one = []
     signal = list(sig)
     for i in signal:
         index += 1
         if i == '0':
             onecounter = 0
         else:
             onecounter += 1
         if onecounter == 5:
             one.append(index)
             onecounter = 0
     k = 0
     for i in one:
         signal.insert(i + k, '0')
         k += 1
     str1 = ""
     for ele in signal:
         str1 += ele
     return str1

binary_string=""
for char in file_pdf:
      binary_string+=(str(bin(ord(char)))[2:])

stuffed_binary_string = bitStuffing(binary_string)

n = int(input("Enter the size of frames for bit stuffing:"))
framesize = pow(2,n)
binsize = len(stuffed_binary_string)
counted =0
framelist = []
framecount =0

while counted < binsize:
     frameinst = Frame(stuffed_binary_string[counted:framesize+counted],framesize)
     counted += framesize
     framelist.append(frameinst)
     framecount += 1

with open('Bin_frame.txt', 'w') as f:
     for inst in framelist:

          f.write(str(inst.size)+" ")
          f.write(inst.data)
          f.write("\n")

          f.write(str(framecount)+" "+str(binsize))