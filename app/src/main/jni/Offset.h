lib l2cpp;
Address 
_Transform, 
_GetPositionInjected0, 
_GetPositionInjected1, 
_GetPositionInjected2, 
_GetPositionInjected3, 
_WorldToScreenPointIntInjected0, 
_WorldToScreenPointIntInjected1, 
_WorldToScreenPointIntInjected2, 
_WorldToScreenPointIntInjected3, 
_Camera;

void getAddress() {
l2cpp.name = "libil2cpp.so";
l2cpp.open();

//Normal Example 
Uclass ComponentClass = l2cpp.getClass("UnityEngine", "Component");
_Transform = ComponentClass.dump("get_transform", 0);

// Unity old and New GetPositionInjected index 0 -> 3
Uclass TransformClass = l2cpp.getClass("UnityEngine", "Transform");
_GetPositionInjected0 = TransformClass.dump("get_position_Injected", 0);
_GetPositionInjected1 = TransformClass.dump("get_position_Injected", 1);
_GetPositionInjected2 = TransformClass.dump("get_position_Injected", 2);
_GetPositionInjected3 = TransformClass.dump("get_position_Injected", 3);

// Unity old and New WorldToScreenPointIntInjected index 0 -> 3
Uclass CameraClass = l2cpp.getClass("UnityEngine", "Camera");
_WorldToScreenPointIntInjected0 = CameraClass.dump("WorldToScreenPoint_Injected", 0);
_WorldToScreenPointIntInjected1 = CameraClass.dump("WorldToScreenPoint_Injected", 1);
_WorldToScreenPointIntInjected2 = CameraClass.dump("WorldToScreenPoint_Injected", 2);
_WorldToScreenPointIntInjected3 = CameraClass.dump("WorldToScreenPoint_Injected", 3);

_Camera = CameraClass.dump("get_main", 0);

}
