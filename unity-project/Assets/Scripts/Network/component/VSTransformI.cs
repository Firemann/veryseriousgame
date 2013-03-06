using UnityEngine;
using System.Collections;

namespace vsm.component
{
    public class VSTransformI : VSTransform
    {
        private Transform unityTransform;

        public VSTransformI(Transform transform)
        {
            this.unityTransform = transform;
        }

        public override void translate(VSVector3 translation, Ice.Current current__)
        {
            MonoBehaviour.print("Up !");
            Vector3 v = VSComponentTools.toUnityVector3(translation);
            MonoBehaviour.print("Up Async !");
            Loom.QueueOnMainThread(() =>
            {
                MonoBehaviour.print("Up Queue !");
                unityTransform.Translate(v);
            });
            MonoBehaviour.print("Done.");
            
        }

        public override void rotate(VSVector3 translation, Ice.Current current__)
        {
            throw new System.NotImplementedException();
        }
    }
}
