# [Unity Script Lifecycle Flowchart](https://docs.unity3d.com/2021.3/Documentation/Manual/ExecutionOrder.html)
## Initialization
1. Awake
2. OnEnalbe
3. Start

## Physics
4. FixedUpdate
5. OnTriggerXXX
6. OnCollisionXXX
7. yield WaitFixedUpdate
## Input events
8. OnMouseXXX
## Game logic
9. Update
10. yield null
11. yield WaitForSeconds
12. yield WWW
13. yield StartCorutine
#### Process Animation
14. LateUpdate
#### Rendering (Scene, Gizmo, GUI)
15. yield WaitForEndOfFrame
16. OnDisable
