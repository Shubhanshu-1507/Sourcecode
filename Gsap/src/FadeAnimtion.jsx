import React , {useRef} from 'react'
import { gsap } from 'gsap/gsap-core';
import {useGSAP} from '@gsap/react'


gsap.registerPlugin(useGSAP);

const FadeAnimtion = () => {

    const h2=useRef(null);

    const h4=useRef(null);

    useGSAP(()=>{
        const tl = gsap.timeline();

        tl.from(h2.current,{
            opacity:0,
            duration:1,
            ease:"power2.out",
            delay:0.5,
            y:-30
        })

        tl.from("h4",{
            opacity: 0,
            duration: 1,
            ease: "power2.out",
            delay: 0.5,
            y: -30,
            stagger:1,
        })

        tl.from("p",{
            opacity: 0,
            duration: 1,
            ease: "power2.out",
            delay: 0.5,
            y: -60,
        })

        tl.to("p",{
            scaleX:1.5
        })
    })

  return (
    <>

    <div className="flex items-center justify-between p-6 text-lg">

        <h2 ref={h2} className='capitalize'>logo</h2>

        <div className="flex gap-7 text-lg capitalize">
            <h4 ref={h4}>home</h4>
            <h4 ref={h4}>courses</h4>
            <h4 ref={h4}>about</h4>
            <h4 ref={h4}>contact us</h4>
        </div>
    </div>


          <p className='absolute top-1/2 left-1/2 transform -translate-x-1/2 -translate-y-1/2 text-3xl uppercase'>
              hola coder's
          </p>

    
    </>
  )
}

export default FadeAnimtion