import React  ,{useRef} from 'react'
import { gsap } from 'gsap/gsap-core';
import { useGSAP } from '@gsap/react';


gsap.registerPlugin(useGSAP);
const BasicAnimation = () => {

    const boxRef = useRef(null);
    const circleRef = useRef(null);
    const circle1Ref = useRef(null);
    const circle2Ref = useRef(null);


    //gsap animation starts

    useGSAP(()=>{
        //start applying the gsap animations
        
        gsap.to(boxRef.current,{
            x:1000,
            duration:1,
            delay:1
        })

        gsap.to(circleRef.current, {
            x: 1000,
            duration: 1,
            delay: 1
        })

        gsap.to(circle1Ref.current,{
            x: 1000,
            y:200,
            duration:2,
            delay:2,
            backgroundColor:"blue",
            borderColor:"white",
            borderWidth:2,
            repeat:-1,
            yoyo:true //to get the property like yoyo
        })

        gsap.to(circle2Ref.current, {
            x: 1000,
            y: 200,
            duration: 2,
            delay: 2,
            backgroundColor: "green",
            borderColor: "white",
            borderWidth: 2,
            repeat: -1,
            yoyo: true //to get the property like yoyo
        })


        
    })
  return (
    <>

    <h1 className='text-center my-10 text-3xl uppercase'> basic animation of gsap</h1>
          <div className="h-60 w-60 bg-red-700 my-6" ref={boxRef}  ></div>

          <div className="h-60 w-60 bg-red-700 rounded-full" ref={circleRef} ></div>

          <div className="h-60 w-60 my-6 bg-red-200 rounded-full" ref={circle1Ref} ></div>

          <div className="h-60 w-60 bg-red-300 rounded-full" ref={circle2Ref} ></div>
    </>
  )
}

export default BasicAnimation