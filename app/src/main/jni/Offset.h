lib l2cpp;
Address _Transform, _GetPositionInjected, _WorldToScreenPointIntInjected, _Camera;

void getAddress() {
l2cpp.name = "libil2cpp.so";
l2cpp.open();

//Normal Example 
Uclass ComponentClass = l2cpp.getClass("UnityEngine", "Component");
_Transform = ComponentClass.dump("get_transform", 0);

Uclass TransformClass = l2cpp.getClass("UnityEngine", "Transform");
_GetPositionInjected = TransformClass.dump("get_position_Injected", 0);
if (!_GetPositionInjected)
    _GetPositionInjected = TransformClass.dump("get_position_Injected", 1);
if (!_GetPositionInjected)
    _GetPositionInjected = TransformClass.dump("get_position_Injected", 2);

Uclass CameraClass = l2cpp.getClass("UnityEngine", "Camera");
_WorldToScreenPointIntInjected = CameraClass.dump("WorldToScreenPoint_Injected", 3);
_Camera = CameraClass.dump("get_main", 0);

}
