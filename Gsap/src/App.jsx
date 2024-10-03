import { createBrowserRouter , Link } from "react-router-dom";
import BasicAnimation from './BasicAnimation';
import TextAnimation from './TextAnimation';
import MoreAnimation from "./MoreAnimation";
import TimeLine from "./TimeLine";
import FadeAnimtion from "./FadeAnimtion";
import ScrollAnimation from "./ScrollAnimation";
import ScrollAnim2 from "./ScrollAnim2";
import SvgAnimation from "./SvgAnimation";


function App() {

  return (
    <>
      <div className="App">


        <h1 className='text-center  mt-2 text-8xl uppercase'>gsap learning</h1>

        <div className="topicList">

          <h1 className="uppercase text-xl text-center font-serif">topic</h1>

          <ul className="list-decimal p-2 cursor-pointer">
            <li>
              <Link to='/topic-1'>
                <h2 className='my-4'>Basic animations of gsap</h2>
              </Link>
            </li>
            <li>
              <Link to='/topic-2'>
                <h2 className='my-4'>text animation</h2>
              </Link>
            </li>
            <li>
              <Link to='/topic-3'>
                <h2 className='my-4'>Box animation</h2>
              </Link>
            </li>
            <li>
              <Link to='/topic-4'>
                <h2 className='my-4'>TimeLine in gsap</h2>
              </Link>
            </li>
            <li>
              <Link to='/topic-5'>
                <h2 className='my-4'>text fade in gsap</h2>
              </Link>
            </li>
            <li>
              <Link to='/topic-6'>
                <h2 className='my-4'> scroll trigger in gsap</h2>
              </Link>
            </li>
            <li>
              <Link to='/topic-7'>
                <h2 className='my-4'>scroll animation 2</h2>
              </Link>
            </li>

            <li>
              <Link to='/topic-8'>
                <h2 className='my-4'>svg animation </h2>
              </Link>
            </li>
          </ul>
         

          
          
          
          
          
          


          
        </div>
              


      </div>


    </>
  )
}


const router = createBrowserRouter([
  {
    path:'/',
    element:<App/>
  },
  {
    path:'/topic-1',
    element:<BasicAnimation/>
  },
  {
    path: '/topic-2',
    element: <TextAnimation/>
  },{
    path:'/topic-3',
    element:<MoreAnimation/>
  },{
    path:"/topic-4",
    element:<TimeLine/>
  },{
    path:"/topic-5",
    element:<FadeAnimtion/>
  },{
    path:'/topic-6',
    element:<ScrollAnimation/>
  },{
    path:'/topic-7',
    element:<ScrollAnim2/>
  },{
    path:'/topic-8',
    element:<SvgAnimation/>
  }
])

export default router
