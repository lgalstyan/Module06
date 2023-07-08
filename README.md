Միայն static data member-ներից ու static method-ներից կազմված
classը կոչվում է static class:
Class-ի static data member-ները օգտագործվում են class-ի բոլոր
օբյեկտների համար, քանի որ հիշողության մեջ դրանք նույն տեղնե են զբաղեցնում:
Static data member-ներին հասանելիություն ունեն միայն
1) տվյալ class-ի static method-ները
2) այլ static method-ներ
3) class-ից դուրս այլ method-ներ

Cast_ը հատուկ օպերատոր է, որը տվյալների մի տեսակը փոխարինում է մյուսով:
c++ _ում ունենք 4 տեսակի cast
1) Static Cast.
2) Dynamic Cast.
3) Const Cast.
4) Reinterpret Cast.

1. static_cast<type> (expr)_ը կատարում է ոչ պոլիմորֆիկ cast: Օրինակ, այն կարող է օգտագործվել բազային դասի ցուցիչը ժառանգ դասի ցուցիչի մեջ գցելու համար:

2. dynamic_cast<type> (expr)_ը գործարկվում է runtime, որի ժամանակ ստուգվում է cast լինելու validity(վավերականությունը): Եթե cast_ը չի կարող կատարվել, արտահայտությանը վերագրվում է NULL

3. const_cast<type> (expr)_ի միջոցով փոփոխականը դարձնում ենք const, կամ const փոփոխականը դարձնում ենք ոչ const:

4. reinterpret_cast<type> (expr)_միջոցով հնարավոր է փոխել ցուցիչը ցանկացած այլ տեսակի ցուցիչով: Այն նաև հնարավորություն է տալիս ցուցիչը փոխել  integer type_ի և հակառակը: 
