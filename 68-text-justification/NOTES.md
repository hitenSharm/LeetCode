//      in above case spacesToBeInserted = 5 and spaces in stirng = 4.
//      eachSlot will be 5/4 is 1. ie increase spaces by 1
//output will be -> so_ _fine_ _That_ _all_ _the
//      since 5/4 is not fully divisible. we will find leftOverSpaces = 5%4 = 1;
//      this leftOverSpace will be distributed from left to right ie each slot will get 1,1,1 from left to right
//output will be -> so_ _ _fine_ _That_ _all_ _the
//                        ↑
//                    leftOverSpace added
//if we had more leftoverspaces then it will be added to next slot.
for(int i = 0; i<str.length(); i++){
if(str[i] == ' ' && (eachSlot > 0 || leftOverSpace >0 )){ //we add spaces till (eachSlot > 0 || leftOverSpace >0)
//required noOfSpaces = eachSlot + (leftOverSpace-- > 0 ? 1:0)
//((leftOverSpace--) > 0 ? 1:0) will return 1 if leftoverspace>0.
//(leftOverSpace--) post decrement
int noOfSpaces = eachSlot + ((leftOverSpace--) > 0 ? 1:0);
str.insert(i, noOfSpaces , ' '); //inserting spaces
i+=noOfSpaces;   //increament count with no of spaces inserted each time
}
}
return str;
}
```
​