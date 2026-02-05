lib l2cpp;
Address _Transform, _GetPositionInjected, _WorldToScreenPointIntInjected, _Camera;

void getAddress() {
    lib.name = "libil2cpp.so";
    lib.open();

    // Component
    Uclass ComponentClass = lib.getClass("UnityEngine", "Component");
    _Transform = ComponentClass.dump("get_transform", 0);

    // Transform
    Uclass TransformClass = lib.getClass("UnityEngine", "Transform");
    _GetPositionInjected = TransformClass.dump("get_position_Injected", 0);
    if (_GetPositionInjected.address == 0)
        _GetPositionInjected = TransformClass.dump("get_position_Injected", 1);
    if (_GetPositionInjected.address == 0)
        _GetPositionInjected = TransformClass.dump("get_position_Injected", 2);
    if (_GetPositionInjected.address == 0)
        _GetPositionInjected = TransformClass.dump("get_position_Injected", 3);

    // Camera
    Uclass CameraClass = lib.getClass("UnityEngine", "Camera");
    _WorldToScreenPointIntInjected = CameraClass.dump("WorldToScreenPoint_Injected", 0);
    if (_WorldToScreenPointIntInjected.address == 0)
        _WorldToScreenPointIntInjected = CameraClass.dump("WorldToScreenPoint_Injected", 1);
    if (_WorldToScreenPointIntInjected.address == 0)
        _WorldToScreenPointIntInjected = CameraClass.dump("WorldToScreenPoint_Injected", 2);
    if (_WorldToScreenPointIntInjected.address == 0)
        _WorldToScreenPointIntInjected = CameraClass.dump("WorldToScreenPoint_Injected", 3);

    _Camera = CameraClass.dump("get_main", 0);
}