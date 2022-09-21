#https://onlinejudge.org/external/112/11223.pdf
#11223

from sys import stdin

cases = int(stdin.readline())
dic = {".-":'A', "-...":'B', "-.-.":'C', "-..":'D', ".":'E', "..-.":'F', "--.":'G', "....":'H', "..":'I', ".---":'J', "-.-":'K', ".-..":'L', "--":'M', "-.":'N', "---":'O', ".--.":'P', "--.-":'Q', ".-.":'R', "...":'S', "-":'T', "..-":'U', "...-":'V', ".--":'W', "-..-":'X', "-.--":'Y', "--..":'Z', "-----":'0', ".----":'1', "..---":'2', "...--":'3', "....-":'4', ".....":'5', "-....":'6', "--...":'7',"---..":'8', "----.":'9', ".-.-.-":'.', "--..--":',', "..--..":'?', ".----.":"’", "-.-.--":'!',"-..-.":'/', "-.--.":'(', "-.--.-":')', ".-...":'&', "---...":':', "-.-.-.":';', "-...-":'=', ".-.-.":'+', "-....-": '-', "..--.-": '_', ".-..-.":'"', ".--.-.":'@'}

for i in range(1, cases+1):
    
    cadena = stdin.readline().rstrip('\n')
    cadFinal = []
    ans = False
    
    if cadena[0] != " ":
        cad = [cadena[0]]
    else:
        cad = []

    for n in range(1,len(cadena)):

        if cadena[n] != " ":

            cad.append(cadena[n])
    
        
        elif cadena[n] == " " and cadena[n-1] == " " and ans == False and (len(cad) != 0 or len(cadFinal) != 0):
            cadFinal.append(cadena[n])
            ans = True

        elif cad!=[]:

            cadFinal.append(dic["".join(cad)])
            cad = []
            ans = False

    if cad != []:

        cadFinal.append(dic["".join(cad)])

    print(f"Message #{i}")
    
    print("".join(cadFinal))

    if i < cases:
        print()