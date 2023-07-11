### Որոշակի ինֆորմացիա պրոյեկտը իրականացնելու համար

Միայն static data member-ներից ու static method-ներից կազմված
classը կոչվում է **static class**:
Class-ի static data member-ները օգտագործվում են class-ի բոլոր
օբյեկտների համար, քանի որ հիշողության մեջ դրանք նույն տեղն են զբաղեցնում:

Static data member-ներին հասանելիություն ունեն միայն
* տվյալ class-ի static method-ները
* այլ static method-ներ
* class-ից դուրս այլ method-ներ

**Static member ֆունկցիաները** access ունեն միայն static data member-ների կամ այլ static member ֆունկցիաների վրա: Այսինքն access չունեն class_ի ոչ static data member_ների կամ member ֆունկցիաների վրա:

Մեզ թույլատրվում է կանչել static member ֆունկցիա՝ օգտագործելով օբյեկտը և «.» օպերատորը, սակայն խորհուրդ է տրվում կանչել՝ օգտագործելով դասի անվանումը, «::» օպերատերը և ֆունկցիան();

Ստատիկ անդամի ֆունկցիան կարելի է կանչել նույնիսկ եթե դասի օբյեկտներ չկան

**Cast_ը հատուկ օպերատոր է, որը տվյալների մի տեսակը փոխարինում է մյուսով**:
c++ _ում ունենք 4 տեսակի cast
1) Static Cast.
2) Dynamic Cast.
3) Const Cast.
4) Reinterpret Cast.  

> 1. static_cast<type> (expr)_ը կատարում է ոչ պոլիմորֆիկ cast: Օրինակ, այն կարող է օգտագործվել բազային դասի ցուցիչը ժառանգ դասի ցուցիչի մեջ գցելու համար:

> 2. dynamic_cast<type> (expr)_ը գործարկվում է runtime, որի ժամանակ ստուգվում է cast լինելու validity(վավերականությունը): Եթե cast_ը չի կարող կատարվել, արտահայտությանը վերագրվում է NULL: Դինամիկ_cast-ը կատարում է պոլիմորֆիկ type_երի վրա և կարող է A* ցուցիչը գցել B* ցուցիչի մեջ միայն այն դեպքում, եթե օբյեկտը, որի վրա ցուցիչը ցույց է տալիս իրականում B_ի օբյեկտ է:

> 3. const_cast<type> (expr)_ի միջոցով փոփոխականը դարձնում ենք const, կամ const փոփոխականը դարձնում ենք ոչ const:

> 4. reinterpret_cast<type> (expr)_միջոցով հնարավոր է փոխել ցուցիչը ցանկացած այլ տեսակի ցուցիչով: Այն նաև հնարավորություն է տալիս ցուցիչը փոխել  integer type_ի և հակառակը: 
