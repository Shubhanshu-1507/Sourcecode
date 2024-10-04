import React , {useRef} from 'react'
import { gsap } from 'gsap/gsap-core';
import { useGSAP } from '@gsap/react';

const MoreAnimation = () => {

    const box1 = useRef(null);
    const box2 = useRef(null);
    const box3 = useRef(null);

    gsap.registerPlugin(useGSAP);

    useGSAP(()=>{

        //animation 1
        gsap.to(box1.current,{
            duration:2,
            delay:1,
            rotation:"+=360", 
            x:1200 , 
            backgroundColor:"green",
            repeat:-1,//it tells about how many time you wanto repeat this animation
            yoyo:true, //to shows a property like yoyo
            scale:2
        });


        gsap.from(box2.current,{
            duration:3,
            rotation:"-=360",
            y:100 , 
            x:1200 , 
            backgroundColor:"yellow",
            scale:0.5,
            repeat:-1,
            yoyo:true
        })


        gsap.to(box3.current, {
            duration: 2,
            rotation: "-=360",
            y: 100,
            x: 1200,
            backgroundColor: "orange",
            scale:3,
            repeat: -1,
            yoyo: true
        })

    })

  return (
    <>

          <h1 className='text-center my-10 text-3xl uppercase'> box animation of gsap</h1>
          <div className="box1 h-[100px] w-[100px] bg-blue-500 my-5" ref={box1}></div>
          <div className="box2 h-[100px] w-[100px] bg-blue-600 my-5" ref={box2} ></div>
          <div className="box3 h-[100px] w-[100px] bg-blue-700 my-5" ref={box3} ></div>
    
    </>
  )
}

export default MoreAnimation