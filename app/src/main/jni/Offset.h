lib l2cpp;
Address 
_Transform, 
_GetPosition1, 
_GetPositionInjected1, 
_GetPositionInjected2, 
_WorldToScreenPointIntInjected3, 
_WorldToScreenPointIntInjected4, 
_Camera;

void getAddress() {
l2cpp.name = "libil2cpp.so";
l2cpp.open();

//Normal Example 
Uclass ComponentClass = l2cpp.getClass("UnityEngine", "Component");
_Transform = ComponentClass.dump("get_transform", 0);

// Unity old and New GetPositionInjected GetPosition index 0 -> index 1 -> 2
Uclass TransformClass = l2cpp.getClass("UnityEngine", "Transform");
_GetPosition1 = TransformClass.dump("get_position", 0);
_GetPositionInjected1 = TransformClass.dump("get_position_Injected", 1);
_GetPositionInjected2 = TransformClass.dump("get_position_Injected", 2);

// Unity old and New WorldToScreenPointIntInjected index 3 -> 4
Uclass CameraClass = l2cpp.getClass("UnityEngine", "Camera");
_WorldToScreenPointIntInjected3 = CameraClass.dump("WorldToScreenPoint_Injected", 3);
_WorldToScreenPointIntInjected4 = CameraClass.dump("WorldToScreenPoint_Injected", 4);

_Camera = CameraClass.dump("get_main", 0);

}
