import './assets/scss/app.scss';
import React, { useEffect, useState, useContext } from 'react';
import { BrowserRouter, Routes, Route, Navigate } from 'react-router-dom';
import { AuthContext } from './context/AuthContext';

import logo from './logo.svg';
import './App.css';

import Login from './components/pages/Login/Login'
import Register from './components/pages/Register/Register'
import Page1 from './components/pages/Page1/Page1'
import Page2 from './components/pages/Page2/Page2'
import Page3 from './components/pages/Page3/Page3'

function App() {

  const {currentUser} = useContext(AuthContext)

  const RequireAuth = ({children}) => {
    return currentUser ? (children) : <Navigate to="/login"/>
  }

  return (
    <div className="App">
      <BrowserRouter>
        <Routes>
          <Route path="/">
            <Route path='/login' element={<Login/>} />
            <Route path='/register' element={<Register/>} />
            <Route index element={<RequireAuth><Page1/></RequireAuth>} />
            <Route path='/page2' element={<RequireAuth><Page2/></RequireAuth>} />
            <Route path='/page3' element={<RequireAuth><Page3/></RequireAuth>} />
          </Route>
        </Routes>
      </BrowserRouter>
    </div>
  );
}

export default App;
