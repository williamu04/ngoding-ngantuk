import './App.css';
import Header from './Header';
import Sidebar from './Sidebar';
import RecommendedVideos from './RecommendedVideos';
import SearchPage from './SearchPage';
import {BrowserRouter as Router, Route, Routes} from "react-router-dom";

function App() {
  return (
    <div className="app">
      <Router>
        <Header/>
        <Routes>
          
          <Route path='/search/:search_term'
          element= {
            <div className='app_page'>
              <Sidebar/>
              <SearchPage/>
            </div>
          }>
          </Route>

          <Route path='/'
          element= {
            <div className='app_page'>
              <Sidebar/>
              <RecommendedVideos/>
            </div>
          }>    
          </Route>

        </Routes>
      </Router>
    </div>
  );
}

export default App;
