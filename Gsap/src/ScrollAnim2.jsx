import React from 'react'
import { gsap } from 'gsap/gsap-core'
import {useGSAP}  from '@gsap/react'
import { ScrollTrigger } from 'gsap/ScrollTrigger'



gsap.registerPlugin(useGSAP,ScrollTrigger);



const ScrollAnim2 = () => {

    useGSAP(()=>{
        gsap.from("#page1 .firstText",{
            opacity:0,
            duration:2,
            scale:3,
            delay:0.5

        })

        gsap.from("#page2 .secondText", {
            opacity: 0,
            duration: 1,
            scale: 3,
            scrollTrigger:{
                trigger:'#page2 .secondText',
                markers:true,
                scrub:2, //used to sync our animation with the scroll,
            }

        })



        gsap.to('#page3 .thirdText',{
            duration:3,
            transform:"translateX(-100%)",
            scrollTrigger:{
                trigger:"#page3", //if you have used pin then you need to trigger the parent of the element at which you have applied animation
                scroller:"body",
                markers:true,
                start:'top 0%',
                end:'top -100%',
                scrub:2,
                pin:true //pin is used to pin a specific part until the animation is over


            }

        })
    })
  return (
    <>

          <div id="page1" className="min-h-screen w-full bg-slate-500 flex justify-center items-center">
              <h1 className='firstText text-4xl'>Hola developer's </h1>
          </div>

          <div id='page2' className="min-h-screen w-full bg-slate-600 flex justify-center items-center">
              <h1 className='secondText text-4xl'>hope you are doing well !!</h1>
          </div>

          <div id='page3' className="page1 min-h-screen w-full bg-slate-700">
              <h1 className='thirdText text-[20vw] w-full text-nowrap  font-semibold'>how's you buddy</h1>
          </div>

          <div id='page4' className="page1 min-h-screen w-full bg-slate-800 flex justify-center items-center">
              <h1 className='fourthText  text-nowrap overflow-x-hidden font-semibold'>the end</h1>
          </div>
    
    </>
  )
}

export default ScrollAnim2