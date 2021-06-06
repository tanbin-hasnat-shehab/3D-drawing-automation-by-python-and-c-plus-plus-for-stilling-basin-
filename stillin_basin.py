from tkinter import *
import os
root=Tk()
root.title("stilling basin")
root.geometry("800x300")


def cal1():
    std_iD=std_id.get()
    B=b.get()
    Tw=tw.get()
    U1=u1.get()
    Tw=tw.get()
    Name=name.get()
    
    f = open("inputs.txt", "w")
    f.write(str(std_iD)+"\n"+str(B)+"\n"+str(Tw)+"\n"+str(U1)+"\n"+Name)
    f.close()
    os.startfile("irr8mod.exe")
    


'''def selected(event):
    dec=clicked.get()
    if dec=='yes':
        q=Entry(root,width=20,borderwidth=5)
        q.grid(row=1,column=2)
        Q=q.get()
        
    else:
        stdid88=Label(root,text="",width=20,padx=20,pady=10).grid(row=1,column=2)'''
        
    

       


def drawing_codes():
    os.startfile("drawing_codes_for_autocad_16_or_higher.txt")
    


def reports_doc():
    os.startfile("calculations.docx")












options=["yes","no"]
clicked=StringVar()
clicked.set(options[0])


stdid=Label(root,text="enter last 3 digits of student id",padx=150,pady=10).grid(row=0,column=0)
std_id=Entry(root,width=20,borderwidth=5)
std_id.grid(row=0,column=1)



'''stdid1=Label(root,text="input discharge ? ",padx=150,pady=10).grid(row=1,column=0)
drop=OptionMenu(root,clicked,*options,command=selected).grid(row=1 ,column=1 )'''



stdid2=Label(root,text="basin width (such as 200m)",padx=100,pady=10).grid(row=2,column=0)
b=Entry(root,width=20,borderwidth=5)
b.grid(row=2,column=1)



stdid3=Label(root,text="upstream velocity (such as 22 m/s)",padx=100,pady=10).grid(row=3,column=0)
u1=Entry(root,width=20,borderwidth=5)
u1.grid(row=3,column=1)
U1=u1.get()

stdid4=Label(root,text="expected tail-water depth (such as 18m)",padx=100,pady=10).grid(row=4,column=0)
tw=Entry(root,width=20,borderwidth=5)
tw.grid(row=4,column=1)
Tw=tw.get()


stdid5=Label(root,text="what name to insert on drawing dwg",padx=100,pady=10).grid(row=5,column=0)
name=Entry(root,width=20,borderwidth=5)
name.grid(row=5,column=1)



caln=Button(root,text="calculate",command=cal1   ,width=15,borderwidth=5,padx=5,pady=5).grid(row=6,column=0)
dw=Button(root,text="drawing codes",command=drawing_codes  ,width=15,borderwidth=5,padx=5,pady=5).grid(row=6,column=1)
doc=Button(root,text="reports",command=reports_doc   ,width=15,borderwidth=5,padx=5,pady=5).grid(row=6,column=2)


    









root.mainloop()


