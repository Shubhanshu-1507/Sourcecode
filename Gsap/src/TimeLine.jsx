import React, { useRef } from 'react'
import { gsap } from 'gsap/gsap-core';
import { useGSAP } from '@gsap/react';

const TimeLine = () => {

    const box1 = useRef(null);
    const box2 = useRef(null);
    const box3 = useRef(null);
    const box4 = useRef(null);
    const box5 = useRef(null);
    const box6 = useRef(null);

    gsap.registerPlugin(useGSAP);

    useGSAP(()=>{

        // timeline is used when you want your animation to run after the previous animation is finish or executed
        const tl = gsap.timeline();

        tl.to(box1.current, {
            duration:2,
            x: 800,
            ease: "power2.out",
            delay:0.5,
            backgroundColor:"cadetBlue"
        })

        tl.to(box2.current, {
            duration:2,
            x: 800,
            ease: "power2.out",
            delay: 0.5,
            backgroundColor:"CornflowerBlue"
        })

        tl.to(box3.current, {
            duration: 2,
            x: 800,
            ease: "power2.out",
            delay: 0.5,
            backgroundColor:"CornflowerBlue"
        })

        tl.from(box4.current, {
            duration: 2,
            x: 800,
            ease: "power2.out",
            delay: 0.5,
            backgroundColor: "CornflowerBlue"
        })

        tl.from(box5.current, {
            duration: 2,
            x: 800,
            ease: "power2.out",
            delay: 0.5,
            backgroundColor: "CornflowerBlue"
        })

        tl.from(box6.current, {
            duration: 2,
            x: 800,
            ease: "power2.out",
            delay: 0.5,
            backgroundColor: "CornflowerBlue"
        })

    })

  return (
    <>

          <h1 className='text-center my-10 text-3xl uppercase'> time line in gsap</h1>

          <div className="box1 h-[100px] w-[100px] bg-pink-100 my-5" ref={box1}></div>
          <div className="box2 h-[100px] w-[100px] bg-pink-200 my-5" ref={box2} ></div>
          <div className="box3 h-[100px] w-[100px] bg-pink-300 my-5" ref={box3} ></div>

          <div className="box1 h-[100px] w-[100px] bg-pink-400 my-5" ref={box4}></div>
          <div className="box2 h-[100px] w-[100px] bg-pink-500 my-5" ref={box5} ></div>
          <div className="box3 h-[100px] w-[100px] bg-pink-600 my-5" ref={box6} ></div>
    
    </>
  )
}

export default TimeLine