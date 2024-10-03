import React from 'react'
import { gsap } from 'gsap/gsap-core'
import {useGSAP} from '@gsap/react'
import { ScrollTrigger } from 'gsap/ScrollTrigger'


//always register the plugin before using it
gsap.registerPlugin(useGSAP,ScrollTrigger);

const ScrollAnimation = () => {

    // the scroll trigger is a property in gsap where we want to trigger an animation  only when we reach at the animation other if we simply appply animation to both box as shown below then both the animation occur at the same time and when scroll to the page2 then we cant see the animation of box2.

    

    useGSAP(()=>{
        gsap.to("#page1 #box1",{
            duration:2,
            rotate:"+=360",

            
        })

        gsap.to("#page2 #box2", {
            duration: 2,
            rotate: "+=360",
            scrollTrigger:{
                trigger:'#page2 #box2', //write that which you want to target at the time of scroll
                scroller:'body',
                markers:true,
                start:"top 70%"
            }


        })
    })
  return (
   <>

   <h1 className='text-white text-center uppercase text-4xl'>scroll trigger in gsap</h1>

              <div id="page1" className="min-h-screen w-full bg-gray-500 flex justify-center items-center">
                  <div id='box1' className="box h-[200px] w-[200px] bg-red-300"></div>
              </div>

              <div id='page2' className="min-h-screen w-full bg-gray-600 flex justify-center items-center">
                  <div id='box2' className="box h-[200px] w-[200px] bg-red-400"></div>
              </div>

              <div id='page3' className="page1 min-h-screen w-full bg-gray-700 flex justify-center items-center">
                  <div id='box3' className="box h-[200px] w-[200px] bg-red-500"></div>
              </div>


   
   </>
  )
}

export default ScrollAnimation