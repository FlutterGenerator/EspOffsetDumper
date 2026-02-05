lib l2cpp;
Address _Transform, _GetPositionInjected, _WorldToScreenPointIntInjected, _Camera;

// Дополнительные переменные для теста всех индексов (чтобы видеть, какой рабочий)
Address posInjected[4];          // для get_position_Injected 0..3
Address w2sInjected[4];          // для WorldToScreenPoint_Injected 0..3

void getAddress() {
    l2cpp.name = "libil2cpp.so";
    l2cpp.open();

    // Normal Example 
    Uclass ComponentClass = l2cpp.getClass("UnityEngine", "Component");
    _Transform = ComponentClass.dump("get_transform", 0);  // всегда 0

    Uclass TransformClass = l2cpp.getClass("UnityEngine", "Transform");

    // Все варианты get_position_Injected (0,1,2,3)
    posInjected[0] = TransformClass.dump("get_position_Injected", 0);
    posInjected[1] = TransformClass.dump("get_position_Injected", 1);
    posInjected[2] = TransformClass.dump("get_position_Injected", 2);
    posInjected[3] = TransformClass.dump("get_position_Injected", 3);

    // Выбери рабочий индекс здесь (раскомментируй один)
    _GetPositionInjected = posInjected[0];   // ← чаще всего 0 в новых Unity (2023+)
    // _GetPositionInjected = posInjected[1];
    // _GetPositionInjected = posInjected[2];
    // _GetPositionInjected = posInjected[3];

    Uclass CameraClass = l2cpp.getClass("UnityEngine", "Camera");

    // Все варианты WorldToScreenPoint_Injected (0,1,2,3)
    w2sInjected[0] = CameraClass.dump("WorldToScreenPoint_Injected", 0);
    w2sInjected[1] = CameraClass.dump("WorldToScreenPoint_Injected", 1);
    w2sInjected[2] = CameraClass.dump("WorldToScreenPoint_Injected", 2);
    w2sInjected[3] = CameraClass.dump("WorldToScreenPoint_Injected", 3);

    // Выбери рабочий индекс здесь (раскомментируй один)
    _WorldToScreenPointIntInjected = w2sInjected[3];   // ← часто 1 или 3
    // _WorldToScreenPointIntInjected = w2sInjected[1];
    // _WorldToScreenPointIntInjected = w2sInjected[0];
    // _WorldToScreenPointIntInjected = w2sInjected[2];

    _Camera = CameraClass.dump("get_main", 0);  // всегда 0
}