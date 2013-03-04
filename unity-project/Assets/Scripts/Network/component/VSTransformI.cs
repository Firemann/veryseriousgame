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
            MonoBehaviour.print("Transformation !");
            //unityTransform.Translate(VSComponentTools.toUnityVector3(translation));
        }

        public override void rotate(VSVector3 translation, Ice.Current current__)
        {
            throw new System.NotImplementedException();
        }
    }
}
